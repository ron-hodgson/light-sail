import math

gamma = 2.6

def gamma8(pixel):
    return int(math.pow((pixel)/255.0,gamma)*255.0+0.5)

def rgb(red, green, blue):
    return (red & 255) << 16 | (green & 255) << 8 | (blue & 255)
