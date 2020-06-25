int yes_prg_start()
{
  char text[16];
  if (argc == 2)
    strcpy(text, argv[1]);
  else
    strcpy(text, "yes");
  while (1)
    Serial.println(text);
}
