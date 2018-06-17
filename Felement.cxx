class Felement {
	protected:
		int zNumber;
		int zDofPerNode;
		std::vector<int> zNodes;
	
	public:
		Felement(int& pNumber, std::vector<int>& pNodes, int& pDofPerNode) {
			zNumber = pNumber;
			zNodes = pNodes;
			zDofPerNode = pDofPerNode;
		}
		
		void set_number(int& pNumber) {
			zNumber = pNumber;
		}
		
		int get_number() {
			return zNumber;
		}
		
		std::string toString() {
			std::string lValue = "";
			/*
			std::vector<int>::const_iterator iter;// = zNodes.begin();
			std::vector<int>::const_iterator endIter = zNodes.end();
			for (iter = zNodes.begin();iter!=endIter;++iter)
			{
				lValue += std::to_string(*iter) + " ";
			}
			*/
			for (auto &i : zNodes)
				lValue += std::to_string(i) + " ";
			return lValue;
		}
		
		std::string to_string() {
			return this->toString();
		}
		
		virtual void calcMatrices() =0;
		
		virtual int get_Shape() =0;
		
		virtual int get_MatricesDimensions() =0;
};

class QuadEle : public Felement {
	private:
	int zAnsatztype;
	//int zDofPerNode;
	public:
	QuadEle(int& pNumber, std::vector<int>& pNodes, int& pDofPerNode) : Felement(pNumber, pNodes, pDofPerNode) 
	{
		//zDofPerNode = pDofPerNode;
		switch (pNodes.size())
		{
			case 4: zAnsatztype = 1; break;
			case 8: zAnsatztype = 2; break;
			case 9: zAnsatztype = 3; break;
			default: 
				std::cerr << "\n wrong number of nodes: you initialized a corrupted quad.\n";
		}
	}
	
	int get_Shape() {
		return 3;
	}
	
	 int get_MatricesDimensions() {
	 	return zNodes.size()*zDofPerNode;
	 }
	 
	 void calcMatrices() {
	 	// empty because material model class is missing 
	 }
};