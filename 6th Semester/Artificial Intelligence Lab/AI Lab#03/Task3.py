'''Consider the following scenario where the UAV receives temperature data from the installed
sensors in a residential area. Assume that there are nine sensors installed that are measuring
temperature in centigrade. Develop a Python code to calculate the average temperature
in F.'''

sensorData = [[1,2,3,4,5,6,7,8,9],[12,43,45,67,87,34,67,11,65],[98,45,67,87,88,88,12,34,44]]

class SimpleReflexAgent:
    def __init__(self):
        pass
   
    def action(self, Percept):
        return 9/5*(sum(Percept)/9)+32

class Environment:
    def __init__(self, State = []):
        self.State = State
   
    def getPercept(self):
        return self.State
   
    def changeState(self, newState):
        self.State = newState
   
def runAgent(Agent, Environment, Steps):
    for Step in range(Steps):
        Environment.changeState(sensorData[Step])
        percept = Environment.getPercept()
        action = Agent.action(percept)
        print(f'Step {Step+1}: Percept - {percept}, Action - {action}')
       
runAgent(SimpleReflexAgent(), Environment(), 3)