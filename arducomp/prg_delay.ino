int delay_prg_start()
{
  if (argc < 2)
  {
    Serial.print(argv[0]);
    Serial.print(": Invalid number of arguments\nUsage: ");
    Serial.print(argv[0]);
    Serial.println(" [PIN N°] [TIME]");
    return -1;
  }

  int time = atoi(argv[1]);

  delay(time);
  
  return time;
}
