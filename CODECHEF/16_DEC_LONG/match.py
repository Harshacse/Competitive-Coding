def main():
	f = open("out_py.txt",'r')
	text  = f.read()
	data = text.split("\n")
	f = open("out_c.txt",'r')
	text  = f.read()
	data1 = text.split("\n")
	for i in range(1001):
		if data[i] != data1[i]:
			print i,data[i],data1[i]
	print "done"
main()