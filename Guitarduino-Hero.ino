
void mysetup() {
  // put your setup code here, to run once:
  ledsSetup();
}

void myloop() {
  // put your main code here, to run repeatedly:
  while(ledsLoop());
  exit(0);
}