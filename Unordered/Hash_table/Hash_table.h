#include "../Vector/Vector.h"
#include "../Forward List/Forward_List.h"

class Hash_table{
	private:
		Vector<Forward_List<int>> m_vec;
	public:
		void Hash_function(Vector<int> vec){
			for (int i = 0; i < vec.size(); i++){
				Forward_List<int> list;
				m_vec.push_back(list);
			}
			for (int i = 0; i < vec.size(); i++){
				m_vec[vec[i] % vec.size()].push_front(vec[i]);;
			}
		}
		void print(){
			for (int i = 0; i < m_vec.size(); i++){
				std::cout << "Vec " << i << ": ";
				m_vec[i].print();
				std::cout << std::endl;
			}
		}
};