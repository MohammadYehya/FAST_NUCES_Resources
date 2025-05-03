import math

'''Consider an interactive and cognitive environment (ICE) in which a smart camera is
monitoring robot movement from one location to another. Let a robot be at location A for
some time instant and then moves to point B and eventually reaches at point C and so on
and so forth shown in the Fig. Develop a Python code to calculate a distance between
reference point R (4, 0) of a camera and A, B, and C and N number of locations.'''
points = [(4,8), (8,3), (0, 3)]

class SimpleReflexAgent:
    def __init__(self, loc = (4,0)):
        self.loc = loc
   
    def action(self, Percept):
        return math.sqrt((Percept[0]-self.loc[0])**2 + (Percept[1]-self.loc[1])**2)

class Environment:
    def __init__(self, State = (0,0)):
        self.State = State
   
    def getPercept(self):
        return self.State
   
    def changeState(self, newState):
        self.State = newState
   
def runAgent(Agent, Environment, Steps):
    for Step in range(Steps):
        Environment.changeState(points[Step])
        percept = Environment.getPercept()
        action = Agent.action(percept)
        print(f'Step {Step+1}: Percept - {percept}, Distance - {action}')
       
runAgent(SimpleReflexAgent(), Environment(), 3)