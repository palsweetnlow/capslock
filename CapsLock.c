/*
 * Title: CapsLock
 * Description:
 * Use the CAPS LOCK key to change the cover opening and closing behavior
 * Author: Yoshihiro Satoh (yosihiro.com)
 */
﻿#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
  int caps=0;
  printf("Caps LockキーがONのときには、ノートPCのカバーを閉じても無視するようにします。\n");
  printf("Caps LockキーがOFFのときには、元のカバー設定の内容によらずスリープになります。\n\n");

  while(1) {
    SHORT state = GetKeyState(VK_CAPITAL);
    if (state & 0x0001) {
      if( caps != 2 ) {
        printf("Caps Lock が ON になりました。\n");
        MessageBeep(MB_OK);
        system("powercfg /setdcvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 0");
        system("powercfg /setacvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 0");
        Sleep(1000);
        system("powercfg /setactive SCHEME_CURRENT");
        caps=2;
      }
    } else {
      if( caps != 1 ) {
        printf("\aCaps Lock が OFF になりました。\n");
        system("powercfg /setdcvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 1");
        system("powercfg /setacvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 1");
        Sleep(1000);
        system("powercfg /setactive SCHEME_CURRENT");
        caps=1;
      }
    }
    Sleep(5000);
  }
}
