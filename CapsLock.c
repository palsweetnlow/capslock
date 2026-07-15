/*
 * Title: CapsLock-Gen
 * Description:
 * Use the CAPS LOCK key to launch batch file
 * Author: Yoshihiro Satoh (yosihiro.com)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

void execBat( char *filename ) {
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    fclose(fp);
    printf("Launched: %s\n",filename);
    system(filename);
  } else {
    printf("File does not exist: %s\n",filename);
  }
}

int main() {
  printf("When CAPS lock key is ON, CapsLock-ON.bat is executed.\n");
  printf("When CAPS lock key is OFF, CapsLock-OFF.bat is executed.\n\n");

  bool caps = (GetKeyState(VK_CAPITAL)&0x0001? true: false);
  while(1) {
    SHORT state = GetKeyState(VK_CAPITAL);
    if (state & 0x0001) {
      if( !caps ) {
        printf("The CAPS Key is now ON.\n");
        MessageBeep(MB_OK);
        execBat("CapsLock-ON.bat");
        caps=true;
      }
    } else {
      if( caps ) {
        printf("\aThe CAPS Key is now OFF.\n");
        execBat("CapsLock-OFF.bat");
        caps=false;
      }
    }
    Sleep(5000);
  }
}
