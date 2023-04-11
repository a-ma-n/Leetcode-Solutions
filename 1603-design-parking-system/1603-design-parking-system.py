class ParkingSystem:
    small,med,big=0,0,0
    def __init__(self, big: int, medium: int, small: int):
        if big>0:
            self.big=big
        if medium>0:
            self.med=medium
        if small>0:
            self.small=small

    def addCar(self, ct: int) -> bool:
        if ct==3:
            if self.small>0:
                self.small-=1
                return True
            return False
        if ct==2:
            if self.med>0:
                self.med-=1
                return True
            return False
        if ct==1:
            if self.big>0:
                self.big-=1
                return True
            return False


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)