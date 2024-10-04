class Solution(object):
    def multiply(self, num1, num2):
        lis1 = []
        lis2 = []
        num4 = 0
        num5 = 0
        for i in range(len(num1)):
            lis1.append(num1[i])

        for j in range(len(num2)):
            lis2.append(num2[j])

        for k in range(len(lis1)):
            num4 += int(lis1[k])*10**(len(lis1)-k-1)

            
        for l in range(len(lis2)):
            num5 += int(lis2[l])*10**(len(lis2)-l-1)

        return str(num4*num5)
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        