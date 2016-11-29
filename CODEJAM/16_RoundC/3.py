from collections import defaultdict

def check(dict1):
	for each in dict1:


def main():
	t = int(input)
	i = 0
	while i<t:
		i++
		n = int(input)
		string = []
		variables = []
		dict1 = defaultdict(lambda:list)
		for i in range(n):
			string.append(raw_input())
			temp1 = string[i].split("=")
			temp = temp1[1]
			j = temp.find("(")
			k = temp.find(")")
			temp = temp[j+1:k]
			dict1[temp1[0]].append(temp.split(",")) 

		
		ans = check(dict1)