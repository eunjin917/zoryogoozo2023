def main():
    countStack = []
    exp = []

    input_count = int(input()) #in python, it's no useful
    expression = input().split() #given fraction expression

    for token in expression:
        if token == '(': #start fraction
            countStack.append(0) #number of element
        elif token == ')': # fraction expression ended
            if countStack and countStack[-1] == 3: #if it is valid expression
                newFrac = calc(exp[-3], exp[-2], exp[-1]) # calculate fraction
                del exp[-3:] #delete used
                exp.append(newFrac) #append new frac
                countStack.pop() #one expression ended
                if countStack:
                    countStack[-1] += 1 #if there are more expression, new one is also element
            else:
                print(-1) #it can't fraction expression
                return
        else:
            if(countStack): #fraction expression elements
                countStack[-1] += 1
                exp.append([int(token),1]) #all number can be fraction
            else:
                print(-1)
                return
    
    if countStack:
        print(-1)
        return
    else:
        gcd = GCD(exp[0][0], exp[0][1])
        print(f'{int(exp[0][0]/gcd)} {int(exp[0][1]/gcd)}')

def calc(a, b, c):
    firstfrac = [b[0]*c[1], b[1]*c[0]]

    numerator = (a[0] * firstfrac[1]) + (a[1] * firstfrac[0])
    denominator = a[1] * firstfrac[1]

    secondfrac = [numerator, denominator]
    return secondfrac

def GCD(a, b):
    if b == 0:
        return a
    else:
        return GCD(b, a%b)
    

main()