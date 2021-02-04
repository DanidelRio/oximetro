import serial
# Basado en: https://www.youtube.com/watch?v=vayAp84vea8

arduino_port = "/dev/ttyACM0"
baud = 9600
fileName = "1_E_9pm.csv" #26_D_10pm
samples = 1000
i = 0

ser= serial.Serial(arduino_port, baud)
print("Conectado al puerto Arduino: "+arduino_port)

file = open(fileName, "w")
print("Creo archivo.")

while i < samples:
	getData= ser.readline() #muestra los datos en terminal
	datos = getData.decode('utf-8')
	# Vea: https://stackoverflow.com/questions/31529421/weird-output-
	#value-bvalue-r-n-python-serial-read#31529530
	file.write(datos)
	print(datos) # b'872\n'
	i +=1
print("Terminamos la recoleccion de datos!")	

file.close()


