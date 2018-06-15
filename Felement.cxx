class Felement {
	protected:
		int zNumber;
		std::vector<int> zNodes;
	
	public:
		Felement(int& pNumber, std::vector<int>& pNodes) {
			zNumber = pNumber;
			zNodes = pNodes;
		}
		
		void set_number(int& pNumber) {
			zNumber = pNumber;
		}
		
		int get_number() {
			return zNumber;
		}
		
		std::string toString() {
			std::string lValue = "";
			for(int i=0;i<zNodes.size();i++)
			{
				lValue += std::to_string(zNodes[i]) + " ";
			}
			return lValue;
		}
		
		std::string to_string() {
			return this->toString();
		}
		
		virtual void calcMatrices() =0;
		
		virtual int get_Shape() =0;
		
		virtual int get_MatricesDimensions() =0;
};