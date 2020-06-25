int digitalwrite_prg_start()
{
  if (argc < 3)
  {
    Serial.print(argv[0]);
    Serial.print(": Invalid number of arguments\nUsage: ");
    Serial.print(argv[0]);
    Serial.println(" [PIN N°] [\"HIGH\"/\"LOW\"]");
    return -1;
  }

  int pin = atoi(argv[1]);

  if (pin < 0 || pin >= NUM_DIGITAL_PINS)
  {
    Serial.print(argv[0]);
    Serial.println(": Invalid pin n°.");
    return -1;
  }

  if (strcmp(argv[2], "HIGH") == 0)
    digitalWrite(pin, HIGH);
  else if (strcmp(argv[2], "LOW") == 0)
    digitalWrite(pin, LOW);
  else
  {
    Serial.print(argv[0]);
    Serial.println(": Invalid value.");
    return -1;
  }

  Serial.print(argv[0]);
  Serial.print(": Wrote ");
  Serial.print(argv[2]);
  Serial.print(" to pin ");
  Serial.println(pin);

  return 0;
}
