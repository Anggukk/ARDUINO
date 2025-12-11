import serial
import time

arduino = serial.Serial("COM3", 9600)
time.sleep(1) # 안정적인 통신을 위해 1초 딜레이

print("'1'을 입력하면 led가 켜지고, '0'을 입력하면 led가 꺼진다.")
print("다른 값을 입력하면 python 프로그램 종료")

while 1:
    var = input()

    if var == "1":
        var=var.encode("utf-8")
        arduino.write(var)
        print("LED ON")
        time.sleep(1)
    elif var == "0":
        var=var.encode("utf-8")
        arduino.write(var)
        print("LED OFF")
        time.sleep(1)
    else:
        break