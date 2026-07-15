echo off

set "needPriv=No"
if %needPriv%==Yes (
 :: 管理者権限の確認と昇格処理
 openfiles >nul 2>&1
 if errorlevel 1 (
     echo 権限を昇格して再起動します...
     :: PowerShellを使用して自身を管理者権限で起動
     powershell -Command "Start-Process '%~f0' -Verb RunAs"
     exit /b
 )
)

powershell -Command "(New-Object -ComObject SAPI.SpVoice).Speak(\"キャップスキーがオンになりました\")"

REM ここに実行するコマンドを書く。
REM 以下の例は、パソコンのカバーを閉じたときの動作を無効にする（スリープしない）設定です
powercfg /setdcvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 0
powercfg /setacvalueindex SCHEME_CURRENT SUB_BUTTONS LIDACTION 0
powercfg /setactive SCHEME_CURRENT

REM このファイルと同じファイル名の Powershellスクリプト(.ps1) を起動できる
REM runPowershell が No なら起動しない
REM runPowershell が Yes なら普通に起動する
REM runPowershell が Priv なら管理者で起動する
set "runPowershell=No"
if %runPowershell%==Yes (
  powershell -NoProfile -ExecutionPolicy Unrestricted .\%~n0.ps1
) else if %runPowershell%==Priv (
  powershell -Command "Start-Process powershell.exe -ArgumentList '-ExecutionPolicy Bypass -File \"%~dp0%~n0.ps1\"' -Verb RunAs"
)
