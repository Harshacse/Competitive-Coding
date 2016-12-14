def main():
	s = "50\n"
	for i in range(1,5001):
		s += str(i)
		s += " "
		s += str(i*i+ i*i + 10000)
		s += "\n"
	f = open("3_test.txt",'wb')
	f.write(s)

main()