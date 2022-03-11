class Tree:
    def __init__(self,value):  #inizializzazione della struttura Tree
        self.value = value
        self.left = None  #istanza dei nodi
        self.right = None

    def printNode(self):    #stampa valore del nodo
        print(self.value)

    def insertNode(self,value):   #inserisci un valore nel all'albero
        if self.value:
            if value < self.value:
                if self.left is None:
                    self.left = Tree(value)
                else:
                    self.left.insertNode(value)
            elif value > self.value:
                if self.right is None:
                    self.right = Tree(value)
                else:
                    self.right.insertNode(value)
        else:
            self.value = value

    def printTreeInOrdine(self):       #stampa l'abero in ordine: sx-radice-dx
        if self.left:
            self.left.printTreeInOrdine()
        print(self.value)
        if self.right:
            self.right.printTreeInOrdine()  

    def printTreePreordine(self):     #stampa l'abero in preordine: radice-sx-dx
        print(self.value)
        if self.left:
            self.left.printTreePreordine()
        if self.right:
            self.right.printTreePreordine()  

    def printTreePostordine(self):     #stampa l'abero in postordine: sx-dx-radice
        if self.left:
            self.left.printTreePostordine()
        if self.right:
            self.right.printTreePostordine() 
        print(self.value)
 
    def findNode(self,value):  #funzione che ritorna true se l'elemento dato in input è nell'albero
        if value == self.value:
            return True
        elif value > self.value:
            if self.right:
                return self.right.findNode(value)
        elif value < self.value:
            if self.left:
                return self.left.findNode(value)

    def countDepth(self):    #conta la prodondità dell'albero
        if self.value is None:
            return 0
        else:
                if self.left != None:
                    leftDepth = self.left.countDepth()
                else:
                    leftDepth = 0
                if self.right != None:
                    rightDepth = self.right.countDepth()
                else:
                    rightDepth = 0
                return max(leftDepth, rightDepth) + 1
    
    def addizione(self):     #calcola la somma dei valori presenti nell' albero
        if self.value is None:
            return 0
        else:
            if self.left != None and self.right != None:
                return self.value + self.left.addizione() + self.right.addizione()
            elif self.left is None and self.right != None:
                return self.value + self.right.addizione()
            elif self.left != None and self.right is None:
                return self.value + self.left.addizione()
            else: return self.value

def main():

    albero = Tree(60) #creazione di un albero con diversi nodi
    albero.insertNode(50)
    albero.insertNode(36)
    albero.insertNode(70)
    albero.insertNode(35)

    #stampe in base alla consegna
    print("albero in Ordine")   
    albero.printTreeInOrdine()
    print("albero in Preordine:")
    albero.printTreePreordine()
    print("albero in Postordine:")
    albero.printTreePostordine()


if __name__ == "__main__":
    main()
