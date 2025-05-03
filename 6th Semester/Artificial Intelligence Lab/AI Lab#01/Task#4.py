def SpeedCheck(speed, anniversary):
    inc = 0
    if(anniversary):
        inc = 10
    if speed <= (70 + inc):
        print('No Fine')
    elif speed >= (71+inc) and speed <= (80+inc):
        print('Less Fine')
    elif speed >= (81+inc):
        print('Car Seize')
    
SpeedCheck(90, True)
SpeedCheck(10, False)
SpeedCheck(90, False)