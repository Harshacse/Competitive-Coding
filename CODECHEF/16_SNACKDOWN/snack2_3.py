def main():
	t = int(input())
	for i in range(t):
		n = int(input())
		x = raw_input()
		s = []
		temp = x.split(" ")
		
		dic1 = {}
		for each in temp:
			s.append(int(each))
			if int(each) in dic1:
				dic1[int(each)]+=1	
			else:
				dic1[int(each)]=1
		
		dic2 = {}
		t = []
		temp = t.split(" ")
		for each in temp:
			t.append(int(each))
			if int(each) in dic2:
				dic2[int(each)]+=1	
			else:
				dic2[int(each)]=1
		
		count = 0


main()