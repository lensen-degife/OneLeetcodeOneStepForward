class Solution:
    def addDigits(self, num: int) -> int:
        number = str(num)
        sum = 0
        while len(number) > 1:
            for digit in number:
                sum += int(digit)
            number = str(sum)
            sum = 0
        return int(number)



    