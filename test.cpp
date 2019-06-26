#include "procesos2.cpp"
#include <cstring>

using namespace std;

int main(){
	
	ready_q[0].mod_id(3);
	ready_q[1].mod_id(2);
	ready_q[2].mod_id(5);
	ready_q[3].mod_id(5);
	ready_q[4].mod_id(0);
	ready_q[5].mod_id(1);
	ready_q[6].mod_id(5);
	ready_q[7].mod_id(5);
	
	imprimir_rq();
	
	int c = get_rq_space();
	cout<<c;
	
	return 0;
}
