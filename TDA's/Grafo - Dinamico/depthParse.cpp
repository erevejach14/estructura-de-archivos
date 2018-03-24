template <class T>
void Graph<T> ::depthParse(T e)
{
	Vertex<T> myV(e);
	collNode<Vertex<T>>* origPos = this->findData(myV);

	if(origPos == nullptr)
	{
		throw GraphException("El vertice de origen no existe");
	}

	Collection<CollNode<Vertex<T>*> vertexStack;
	Collection<CollNode<Vertex<T>*> visitedStack;

	CollNode<Vertex<T>>* currentPos;
	CollNode<Vertex<T>>* currentDest;

	vertexStack.push(origPos);
	while(!vertexStack.isEmpty())
	{
		currentPos = vertexStack.pop();

		if(visitedList.findData(currentPos) == nullptr)
		{
			std::cout << currentPos->getElem().getInfo() << ", ";
			visitedList.insertData(currentPos);

			Vertex<T> destList(currentPos->getElem());
			while(!destList.isEmpty())
			{
				currentDest = destList.dequeue().getDest();

				if(visitedList.findData(currentDest) == nullptr)
				{
					vertexStack.push(currentDest);
				}
			}
		}
	}
}