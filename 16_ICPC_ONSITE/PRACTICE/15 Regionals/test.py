def main():
	s = "5000\n"
	for i in range(1,5001):
		s += str(i)
		s += "\n"
	f = open("amss_test.txt",'wb')
	f.write(s)

main()