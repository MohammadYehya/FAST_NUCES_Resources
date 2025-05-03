'''Consider a scenario, cameras placed on every side of the car — front, rear, left and right —
to stitch together a 360-degree view of the environment. For a three-lane road a car is
moving on a middle lane, consider the below scenario
• If the front camera detects the object within range of 8 meters breaks are applied
automatically.
• If the left camera detects the object within range of 2 meters car moves to the right lane.
• If the right camera detects the object within range of 2 meters car moves to the left lane.
• For parking the car if the rear camera detects the object within 5 cm breaks are applied.'''


dist = [(6, 4, 5, 3), (10, 1, 3, 5), (11, 3, 1, 8), (9, 6, 7, 0.01)]

class SimpleReflexAgent:
    def __init__(self):
        pass
   
    def action(self, Percept):
        if Percept[0] < 8 :
            return "Apply Breaks!"
        elif Percept[1] < 2:
            return "Move to Right Lane!"
        elif Percept[2] < 2:
            return "Move to Left Lane!"
        elif Percept[3] < 0.05:
            return "Apply Breaks!" 

class Environment:
    def __init__(self, State = (0,0,0,0)):
        self.State = State
   
    def getPercept(self):
        return self.State
   
    def changeState(self, newState):
        self.State = newState
   
def runAgent(Agent, Environment, Steps):
    for Step in range(Steps):
        Environment.changeState(dist[Step])
        percept = Environment.getPercept()
        action = Agent.action(percept)
        print(f'Step {Step+1}: Percept - {percept}, Action - {action}')
       
runAgent(SimpleReflexAgent(), Environment(), 4)