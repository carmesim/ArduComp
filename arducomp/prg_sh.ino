char _sh_input[1024], _sh_lastChar;

void _sh_getInput()
{
  char* cur_char = _sh_input;
  _sh_lastChar = '\0';
  Serial.print("ArduComp> ");
  while (_sh_lastChar != '\n')
  {
    while (!Serial.available()) {}
    _sh_lastChar = (char) Serial.read();
    *cur_char = _sh_lastChar;
    cur_char++;
  }
  *cur_char = '\0';
  Serial.print(_sh_input);
  _sh_tokenizeInput();
}

void _sh_tokenizeInput()
{
  char *cur_char = _sh_input;
  char current_token = 0;
  char current_token_pos = 0;
  argc = 0;
  while (*cur_char != '\0' && *cur_char != '\n' && argc < _max_argc)
  {
    while (*cur_char != ' ' && *cur_char != '\0' && *cur_char != '\n' && current_token_pos < _max_argl)
    {
      argv[current_token][current_token_pos] = *cur_char;
      current_token_pos++;
      cur_char++;
    }
    argv[current_token][current_token_pos] = '\0';
    current_token++;
    current_token_pos = 0;
    argc++;
    cur_char++;
  }
  _sh_interpretTokens();
}

void _sh_interpretTokens()
{
  if (strcmp(argv[0], "sh") == 0)
    return;
  else if (strcmp(argv[0], "yes") == 0)
    PrgStarts[PrgID::yes]();
  else if (strcmp(argv[0], "pinmode") == 0)
    PrgStarts[PrgID::pinmode]();
  else if (strcmp(argv[0], "digitalwrite") == 0)
    PrgStarts[PrgID::digitalwrite]();
  else
  {
    Serial.print("Unrecognized command ");
    Serial.println(argv[0]);
  }
}

int sh_prg_start()
{
  while (1)
    _sh_getInput();
}
