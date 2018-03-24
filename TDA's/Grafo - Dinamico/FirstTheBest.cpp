template <class T>
Collection<T>& Graph<T>:: firstTheBest(T orig, T dest)
{
	Collection<T> routeList;
	Vertex<T> myOr(orig);
	Vertex<T> myDe(dest);

	CollNode<Vetex<T>>* origPos = this->findData(myOrg);
	CollNode<Vetex<T>>* destPos = this->findData(myDe);

	if(origPos == nullptr or destPos == nullptr)
	{
		throw GraphException("EL vertice de origen y/o destino no existe(n) haciendo...");
	}

	Collection<RoutePair<T>> routeStack;
	WieghtedDest<T> myWeightedDest;
	Collection<WieghtedDest<T>> weightedList;
	Collection<WieghtedDest<T>> currentDest;
	float currentWeight;

	myWeightedDest.setDest(origPos);
	myWeightedDest.setWeight(0);

	while(!orderedList.isEmpty())
	{
		currentPos = orderedList.getFront().getDest();
		currentWeight = orderedList.getFront().getWeight();
		orderedList.dequeue();

		if(currentPos == destPos)
		{
			return getRoute(routeStack, destPos);
		}

		Vertex<T> destList(currentPos->getElement());
		float destCost;
		CollNode<weightedDest<T>>* currentWeightDest;
		RoutePair<T> myPair;

		while(!destList.isEmpty())
		{
			currentDest = destList.getFront().getDest();
			destCost = destList.getFront().getWeight();
			destList().dequeue();

			myWeightedDest.setDest(currentDest);
			myWeightedDest.setWeight(currentWeight + destCost);

			currentWeightDest = weightedList.findData(myWeightedDest);

			if(currentWeight == nullptr or myWeightedDest < currentWeightDest->getElement())
			{
				if(currentWeight != nullptr)
				{
					weightedList.deleteData(currentWeightDest);
				}

				weightedList.insertData(myWeightedDest);
				orderedList.insertOrderedData(myWeightedDest);

				myPair.setOrig(currentPos);
				myPair.setDest(currentPos);
				myPair.setWeight(destCost);
				routeStack.push(myPair);
			}
		}
		routeList;
	}
}