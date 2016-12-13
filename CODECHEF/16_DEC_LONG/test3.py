def check(n,base):
	temp = n%base;
	n = n/base;
	while n!=0:
		temp = n%base
		n = n/base
	return temp

def main():
	f = open("test.txt",'r')
	text = f.read()
	data = text.split("\n")
	string = ""
	t = int(data[0])
	for i in range(1,t+1):
		n = int(data[i])
		s = 0
		for j in range(2,n+1):
			if check(n,j) == 1:
				s += 1
		string += str(s)+"\n"
	f = open("out_py.txt",'wb')
	f.write(string)

def temp(n):
	

	s = 0
	for j in range(2,n+1):
		if check(n,j) == 1:
			s += 1
			print j,
	print ""
	print s

main()