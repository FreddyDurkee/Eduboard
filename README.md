Atmel Studio 7.0

Aby zacząć pracę z Atmel Studio w pierwszych krokach należy skonfigurować ustawienia pod urządzenie na, które wgrany zostanie program. W przypadku pracy z Arduino należy wcześniej pobrać ze strony https://www.arduino.cc/en/Main/Software Arduino IDE. Następnie podążamy za następującymi krokami:

1. Uruchom Arduino IDE i wybierz przykładowy kod: Plik -> Przykłady ->Basics -> Blink
2. W ustawieniach Plik -> Preferencje należy zaznaczyć: pokaż szczegółowe informacje poczas: wgrywania
3. Skompiluj i uruchom kod
4. Skopiuj początkowe linijki do notatnika:

C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude -CC:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:C:\Users\DOMINI~1\AppData\Local\Temp\arduino_build_471310/Blink.ino.hex:i 

5. Rozdziel linijki na:

C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude 

-CC:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:C:\Users\DOMINI~1\AppData\Local\Temp\arduino_build_471310/Blink.ino.hex:i 

6. Do pierwszej lini na końcu dopisz .exe:
C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude.exe

7. W drugiej linijce należy wszystkie ścieżki wziąć w nawias, w przeciwnym wypadku Atmel Studio nie zaakceptuje naszych ścieżek:

-C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:"C:\Users\DOMINI~1\AppData\Local\Temp\arduino_build_471310/Blink.ino.hex":i 

8. Ponieważ ładować skompilowany plik do Atmel Studio zamiast Arduino IDE musimy zmienić ścieżkę na: 
-Uflash:w:"$(ProjectDir)Debug\$(TargetName).hex":i 

w rezultacie mamy takie dwie linijki:

C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude.exe

-C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:"$(ProjectDir)Debug\$(TargetName).hex":i 

9. Otwórz Atmel Studio i wybierz: New Project -> GCC Executable Project -> ATmega328p (dla Arduino Uno) i zatwierdź

10. Wybierz: Tools -> External Tools... pojawi się wtedy okno

11. Wpisz tytuł, który będziesz mógł później rozpoznać

12. Do Command wklej pierwszą linijkę: 
Command: C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude.exe

13. Analogicznie do Arguments przekopiuj i wklej drugą linijkę

14. Na koniec zaznacz: use Output window i zatwierdź

Po tak wykonanej konfiguracji można rozpocząć prace. 
 