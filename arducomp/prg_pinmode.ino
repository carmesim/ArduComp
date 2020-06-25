int pinmode_prg_start()
{
  if (argc < 3)
  {
    Serial.print(argv[0]);
    Serial.print(": Invalid number of arguments\nUsage: ");
    Serial.print(argv[0]);
    Serial.println(" [PIN N°] [\"INPUT\"/\"OUTPUT\"]");
    return -1;
  }

  int pin = atoi(argv[1]);

  if (pin < 0 || pin >= NUM_DIGITAL_PINS)
  {
    Serial.print(argv[0]);
    Serial.println(": Invalid pin n°.");
    return -1;
  }

  if (strcmp(argv[2], "INPUT") == 0)
    pinMode(pin, INPUT);
  else if (strcmp(argv[2], "OUTPUT") == 0)
    pinMode(pin, OUTPUT);
  else
  {
    Serial.print(argv[0]);
    Serial.println(": Invalid pin type.");
    return -1;
  }

  Serial.print(argv[0]);
  Serial.print(": Pin ");
  Serial.print(pin);
  Serial.print(" set as ");
  Serial.println(argv[2]);

  return 0;
}
