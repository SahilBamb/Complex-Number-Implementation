#
#
# Python version
#
#
import math

class complexC:
    def __init__(self, real=0, img=0):
        self.real = float(real) 
        self.img = float(img)

    def __add__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            other = float(other)
            return complexC(self.real+other.real, self.img)
        elif isinstance(other, complexC):
            return complexC(self.real+other.real, self.img+other.img)
        else:
            raise TypeError

    def __radd__(self, other):
        return self + other

    def __floordiv__(self, other):
        hold = self / other
        return complexC(float(math.floor(hold.real)),float(math.floor(hold.img)))

    def __rfloordiv__(self, other):
        hold = other / self
        return complexC(float(math.floor(hold.real)),float(math.floor(hold.img)))

    def __truediv__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            other = float(other)
            return complexC(self.real/other,self.img/other)
        elif isinstance(other, complexC):
            numer = complexC( (self.real*other.real) + (self.img*other.img), (self.img*other.real) - (self.real*other.img) )
            denom = (other.real**2 + other.img**2)
            return numer / denom
        else:
            raise TypeError

    def __rtruediv__(self, other):
        return complexC(other) / self

    def __float__(self):
         return float(self.real)

    def __int__(self):
         return int(self.real)

    def __mul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            other = float(other)
            return complexC(self.real*other, self.img*other)
        elif isinstance(other, complexC):
            return complexC( (self.real*other.real) - (self.img*other.img), (self.real*other.img + other.real*self.img))
        else:
            raise TypeError

    def __rmul__(self, other):
        return self * other

    def __str__(self):
        return f'({self.real} + {self.img}i)' if self.img>=0 else f'({self.real} - {abs(self.img)}i)'

    def __sub__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            other = float(other)
            return complexC(self.real-other.real, self.img)
        elif isinstance(other, complexC):
            return complexC(self.real-other.real, self.img-other.img)
        else:
            raise TypeError

    def __rsub__(self, other):
        return (-1 * self) + other

if __name__ == '__main__':

    a = complexC(1.0, 2.0)
    b = complexC(1.0, 3.0)

    i = 5.0

    print('%s + %s = %s' % (a, b, a + b))
    print('%s - %s = %s' % (a, b, a - b))
    print('%s * %s = %s' % (a, b, a * b))
    print('%s / %s = %s' % (a, b, a / b))
    print('------------------------------------')
    print('%s + %s = %s' % (b, a, b + a))
    print('%s - %s = %s' % (b, a, b - a))
    print('%s * %s = %s' % (b, a, b * a))
    print('%s / %s = %s' % (b, a, b / a))
    print('------------------------------------')
    print('%s + %s = %s' % (a, i, a + i))
    print('%s - %s = %s' % (a, i, a - i))
    print('%s * %s = %s' % (a, i, a * i))
    print('%s / %s = %s' % (a, i, a / i))
    print('------------------------------------')
    print('%s + %s = %s' % (i, a, i + a))
    print('%s - %s = %s' % (i, a, i - a))
    print('%s * %s = %s' % (i, a, i * a))
    print('%s / %s = %s' % (i, a, i / a)) 
    print('------------------------------------')
    print('%s // %s = %s' % (i, a, i // a)) 
    print('%s // %s = %s' % (a, i, a // i)) 
    print('%s // %s = %s' % (a, b, a // b))
    print('%s // %s = %s' % (b, a, b // a)) 

