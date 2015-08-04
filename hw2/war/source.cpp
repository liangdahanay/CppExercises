#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

static int redLife = 0;
static int blueLife = 0;

static bool availableRed(int life){
	return life<=redLife;
}
	
static bool availableBlue(int life){
	return life<=blueLife;
}

class Iceman{
public:
	static int redIceman;
	static int blueIceman;
	
	const unsigned int id;
	const int life;
	const int attack = 0;
	const string group;//0 for red, 1 for blue
	const string name;
	
	Iceman(int _life, int _id, string _group)
	:id(_id),life(_life),group(_group),name("iceman")
	{
		if( group.compare("blue")==0 ){
			blueLife-=life;
			blueIceman++;
		}else if( group.compare("red")==0 ){
			redLife-=life;
			redIceman++;
		}
	}
	~Iceman(){
		if( group.compare("blue")==0 ){
			blueIceman--;
		}else if( group.compare("red")==0 ){
			redIceman--;
		}
	}
	
	string getName() const {
		return name;
	}
	
	string getGroup() const {
		return group;
	}
	
	int getRemain() const{
		if( group.compare("blue")==0 ){
			return blueIceman; 
		}else if( group.compare("red")==0 ){
			return redIceman; 
		}
		return 0;
	}
	
	void print(int time) const {
		cout << setfill('0') << setw(3);
		cout << time << " " 
			<< getGroup() << " " 
			<< getName() <<  " "
			<< id << " "
			<< "born with strength " << life << ","
			<< getRemain() << " "
			<< getName() << " in " << getGroup() << " headquarter" << endl;
	}
};
int Iceman::redIceman = 0;
int Iceman::blueIceman = 0;

class Lion{
public:
	static int redLion;
	static int blueLion;
	
	const unsigned int id;
	const int life;
	const int attack = 0;
	const string group;//0 for red, 1 for blue
	const string name;
	
	Lion(int _life, int _id, string _group)
	:id(_id),life(_life),group(_group),name("lion")
	{
		
		if( group.compare("blue")==0 ){
			blueLife-=life;
			blueLion++;
		}else if( group.compare("red")==0 ){
			redLife-=life;
			redLion++;
		}
	}
	~Lion(){
		if( group.compare("blue")==0 ){
			blueLion--;
		}else if( group.compare("red")==0 ){
			redLion--;
		}
	}
	
	string getName() const {
		return name;
	}
	string getGroup() const {
		return group;
	}
	
	int getRemain() const{
		if( group.compare("blue")==0 ){
			return blueLion; 
		}else if( group.compare("red")==0 ){
			return redLion; 
		}
		return 0;
	}
	
	void print(int time) const {
		cout << setfill('0') << setw(3);
		cout << time << " " 
			<< getGroup() << " " 
			<< getName() <<  " "
			<< id << " "
			<< "born with strength " << life << ","
			<< getRemain() << " "
			<< getName() << " in " << getGroup() << " headquarter" << endl;
	}
};
int Lion::redLion = 0;
int Lion::blueLion = 0;

class Wolf{
public:
	static int redWolf;
	static int blueWolf;
	
	
	const unsigned int id;
	const int life;
	const int attack = 0;
	const string group;//0 for red, 1 for blue
	const string name;
	
	Wolf(int _life, int _id, string _group)
	:id(_id),life(_life),group(_group), name("wolf")
	{
		
		if( group.compare("blue")==0 ){
			blueLife-=life;
			blueWolf++;
		}else if( group.compare("red")==0 ){
			redLife-=life;
			redWolf++;
		}
	}
	
	~Wolf(){
		if( group.compare("blue")==0 ){
			blueWolf--;
		}else if( group.compare("red")==0 ){
			redWolf--;
		}
	}
	
	string getName() const {
		return name;
	}
	string getGroup() const {
		return group;
	}
	
	int getRemain() const{
		if( group.compare("blue")==0 ){
			return blueWolf; 
		}else if( group.compare("red")==0 ){
			return redWolf; 
		}
		return 0;
	}
	
	void print(int time) const {
		cout << setfill('0') << setw(3);
		cout << time << " " 
			<< getGroup() << " " 
			<< getName() <<  " "
			<< id << " "
			<< "born with strength " << life << ","
			<< getRemain() << " "
			<< getName() << " in " << getGroup() << " headquarter" << endl;
	}
};
int Wolf::redWolf = 0;
int Wolf::blueWolf = 0;

class Ninja{
public:
	static int redNinja;
	static int blueNinja;

	const unsigned int id;
	const int life;
	const int attack = 0;
	const string group;//0 for red, 1 for blue
	const string name;
	
	Ninja(int _life, int _id, string _group)
	:id(_id),life(_life),group(_group), name("ninja")
	{
		
		if( group.compare("blue")==0 ){
			blueLife-=life;
			blueNinja++;
		}else if( group.compare("red")==0 ){
			redLife-=life;
			redNinja++;
		}
	}
	
	~Ninja(){
		if( group.compare("blue")==0 ){
			blueNinja--;
		}else if( group.compare("red")==0 ){
			redNinja--;
		}
	}
	
	string getName() const {
		return name;
	}
	string getGroup() const {
		return group;
	}
	
	int getRemain() const{
		if( group.compare("blue")==0 ){
			return blueNinja; 
		}else if( group.compare("red")==0 ){
			return redNinja; 
		}
		return 0;
	}
	
	void print(int time) const {
		cout << setfill('0') << setw(3);
		cout << time << " " 
			<< getGroup() << " " 
			<< getName() <<  " "
			<< id << " "
			<< "born with strength " << life << ","
			<< getRemain() << " "
			<< getName() << " in " << getGroup() << " headquarter" << endl;
	}
};
int Ninja::redNinja = 0;
int Ninja::blueNinja = 0;

class Dragon{
public:
	static int redDragon;
	static int blueDragon;
	
	const unsigned int id;
	const int life;
	const int attack = 0;
	const string group;//0 for red, 1 for blue
	const string name;
	
	Dragon(int _life, int _id, string _group)
	:id(_id),life(_life),group(_group), name("dragon")
	{
		
		if( group.compare("blue")==0 ){
			blueLife-=life;
			blueDragon++;
		}else if( group.compare("red")==0 ){
			redLife-=life;
			redDragon++;
		}
	}
	~Dragon(){
		if( group.compare("blue")==0 ){
			blueDragon--;
		}else if( group.compare("red")==0 ){
			redDragon--;
		}
	}
	
	string getName() const {
		return name;
	}
	string getGroup() const {
		return group;
	}
	
	int getRemain() const{
		if( group.compare("blue")==0 ){
			return blueDragon; 
		}else if( group.compare("red")==0 ){
			return redDragon; 
		}
		return 0;
	}
	
	void print(int time) const {
		cout << setfill('0') << setw(3);
		cout << time << " " 
			<< getGroup() << " " 
			<< getName() <<  " "
			<< id << " "
			<< "born with strength " << life << ","
			<< getRemain() << " "
			<< getName() << " in " << getGroup() << " headquarter" << endl;
	}
};
int Dragon::redDragon = 0;
int Dragon::blueDragon = 0;

int main(int argc, char** argv){
	int caseNum;
	vector<int> totalLifeVector;
	vector<int> dragonLifeVector, 
		ninjaLifeVector, 
		icemanLifeVector, 
		lionLifeVector, 
		wolfLifeVector;
		
	cin >> caseNum;
	
	for(int i=0; i<caseNum; i++){
		int totalLife, dragonLife, ninjaLife, icemanLife, lionLife, wolfLife;
		
		cin >> totalLife;
		totalLifeVector.push_back(totalLife);
		cin >> dragonLife 
			>> ninjaLife 
			>> icemanLife
			>> lionLife 
			>> wolfLife;
			
		dragonLifeVector.push_back(dragonLife); 
		ninjaLifeVector.push_back(ninjaLife);
		icemanLifeVector.push_back(icemanLife);
		lionLifeVector.push_back(lionLife);
		wolfLifeVector.push_back(wolfLife);
		
	}
	
	
	
	for(int i = 0; i < caseNum; i++){
		redLife = blueLife = totalLifeVector[i];
		cout << "Case:" << i + 1 << endl;
		
		int redId = 0; 
		int blueId = 0;
		
		vector<Iceman* > redAllIcemans; 
		Iceman* redIceman = NULL;
		
		vector<Iceman* > blueAllIcemans; 
		Iceman* blueIceman = NULL;
			
		vector<Lion* > redAllLions; 	
		Lion* redLion = NULL;
		
		vector<Lion* > blueAllLions; 
		Lion* blueLion = NULL;
		
		vector<Wolf* > redAllWolfs; 
		Wolf* redWolf = NULL;
		
		vector<Wolf* > blueAllWolfs; 
		Wolf* blueWolf = NULL;
		
		vector<Ninja* > redAllNinjas;
		Ninja* redNinja = NULL;
		
		vector<Ninja* > blueAllNinjas;
		Ninja* blueNinja = NULL;
		
		vector<Dragon* > redAllDragons;
		Dragon* redDragon = NULL;
		
		vector<Dragon* > blueAllDragons;
		Dragon* blueDragon = NULL;
		
		int time = 0;
		bool redFinished = false;
		bool blueFinished = false;
		while( 1 ){
			
			redId++;
			blueId++;
			
			if(time%5==0){
				if( availableRed(icemanLifeVector[i]) ){
					redIceman = new Iceman( icemanLifeVector[i], redId, "red" ); 
					redIceman -> print(time);
					redAllIcemans.push_back( redIceman );
				}else if( availableRed(lionLifeVector[i]) ){
					redLion = new Lion( lionLifeVector[i], redId, "red");
					redLion->print(time);
					redAllLions.push_back( redLion );
				}else if( availableRed(wolfLifeVector[i]) ){
					redWolf = new Wolf( wolfLifeVector[i], redId, "red");
					redWolf->print(time);
					redAllWolfs.push_back(redWolf);
				}else if( availableRed( ninjaLifeVector[i] ) ){
					redNinja = new Ninja( ninjaLifeVector[i], redId, "red" );
					redNinja -> print(time);
					redAllNinjas.push_back(redNinja);
				}else if( availableRed(dragonLifeVector[i]) ){
					redDragon = new Dragon(dragonLifeVector[i], redId, "red");
					redDragon->print(time);
					redAllDragons.push_back(redDragon);
				}else if(!redFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " red headquarter stops making warriors" << endl;
					redFinished = true;
				}
			
			
				if(availableBlue(lionLifeVector[i])){
					blueLion = new Lion( lionLifeVector[i], blueId, "blue");
					blueLion->print(time);
					blueAllLions.push_back( blueLion );
				}else if( availableBlue(dragonLifeVector[i]) ){
					blueDragon = new Dragon(dragonLifeVector[i], blueId, "blue");
					blueDragon->print(time);
					blueAllDragons.push_back(blueDragon);
				}else if( availableBlue(ninjaLifeVector[i]) ){
					blueNinja = new Ninja( ninjaLifeVector[i], blueId, "blue" );
					blueNinja -> print(time);
					blueAllNinjas.push_back(blueNinja);
				}else if( availableBlue(icemanLifeVector[i]) ){
					blueIceman = new Iceman( icemanLifeVector[i], blueId, "blue" ); 
					blueIceman -> print(time);
					blueAllIcemans.push_back( blueIceman );
				}else if( availableBlue(wolfLifeVector[i]) ){
					blueWolf = new Wolf( wolfLifeVector[i], blueId, "blue");
					blueWolf->print(time);
					blueAllWolfs.push_back(blueWolf);
				}else if(!blueFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " blue headquarter stops making warriors" << endl;
					blueFinished = true;
				}	
			}else if(time%5==1){
				if( availableRed(lionLifeVector[i]) ){
					redLion = new Lion( lionLifeVector[i], redId, "red");
					redLion->print(time);
					redAllLions.push_back( redLion );
				}else if( availableRed(wolfLifeVector[i]) ){
					redWolf = new Wolf( wolfLifeVector[i], redId, "red");
					redWolf->print(time);
					redAllWolfs.push_back(redWolf);
				}else if( availableRed( ninjaLifeVector[i] ) ){
					redNinja = new Ninja( ninjaLifeVector[i], redId, "red" );
					redNinja -> print(time);
					redAllNinjas.push_back(redNinja);
				}else if( availableRed(dragonLifeVector[i]) ){
					redDragon = new Dragon(dragonLifeVector[i], redId, "red");
					redDragon->print(time);
					redAllDragons.push_back(redDragon);
				}else if( availableRed(icemanLifeVector[i]) ){
					redIceman = new Iceman( icemanLifeVector[i], redId, "red" ); 
					redIceman -> print(time);
					redAllIcemans.push_back( redIceman );
				}else if(!redFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " red headquarter stops making warriors" << endl;
					redFinished = true;
				}
			
			
				if( availableBlue(dragonLifeVector[i]) ){
					blueDragon = new Dragon(dragonLifeVector[i], blueId, "blue");
					blueDragon->print(time);
					blueAllDragons.push_back(blueDragon);
				}else if( availableBlue(ninjaLifeVector[i]) ){
					blueNinja = new Ninja( ninjaLifeVector[i], blueId, "blue" );
					blueNinja -> print(time);
					blueAllNinjas.push_back(blueNinja);
				}else if( availableBlue(icemanLifeVector[i]) ){
					blueIceman = new Iceman( icemanLifeVector[i], blueId, "blue" ); 
					blueIceman -> print(time);
					blueAllIcemans.push_back( blueIceman );
				}else if( availableBlue(wolfLifeVector[i]) ){
					blueWolf = new Wolf( wolfLifeVector[i], blueId, "blue");
					blueWolf->print(time);
					blueAllWolfs.push_back(blueWolf);
				}else if(availableBlue(lionLifeVector[i])){
					blueLion = new Lion( lionLifeVector[i], blueId, "blue");
					blueLion->print(time);
					blueAllLions.push_back( blueLion );
				}else if(!blueFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " blue headquarter stops making warriors" << endl;
					blueFinished = true;
				}	
				
			}else if(time%5==2){
				if( availableRed(wolfLifeVector[i]) ){
					redWolf = new Wolf( wolfLifeVector[i], redId, "red");
					redWolf->print(time);
					redAllWolfs.push_back(redWolf);
				}else if( availableRed( ninjaLifeVector[i] ) ){
					redNinja = new Ninja( ninjaLifeVector[i], redId, "red" );
					redNinja -> print(time);
					redAllNinjas.push_back(redNinja);
				}else if( availableRed(dragonLifeVector[i]) ){
					redDragon = new Dragon(dragonLifeVector[i], redId, "red");
					redDragon->print(time);
					redAllDragons.push_back(redDragon);
				}else if( availableRed(icemanLifeVector[i]) ){
					redIceman = new Iceman( icemanLifeVector[i], redId, "red" ); 
					redIceman -> print(time);
					redAllIcemans.push_back( redIceman );
				}else if( availableRed(lionLifeVector[i]) ){
					redLion = new Lion( lionLifeVector[i], redId, "red");
					redLion->print(time);
					redAllLions.push_back( redLion );
				}else if(!redFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " red headquarter stops making warriors" << endl;
					redFinished = true;
				}
			
			
				if( availableBlue(ninjaLifeVector[i]) ){
					blueNinja = new Ninja( ninjaLifeVector[i], blueId, "blue" );
					blueNinja -> print(time);
					blueAllNinjas.push_back(blueNinja);
				}else if( availableBlue(icemanLifeVector[i]) ){
					blueIceman = new Iceman( icemanLifeVector[i], blueId, "blue" ); 
					blueIceman -> print(time);
					blueAllIcemans.push_back( blueIceman );
				}else if( availableBlue(wolfLifeVector[i]) ){
					blueWolf = new Wolf( wolfLifeVector[i], blueId, "blue");
					blueWolf->print(time);
					blueAllWolfs.push_back(blueWolf);
				}else if(availableBlue(lionLifeVector[i])){
					blueLion = new Lion( lionLifeVector[i], blueId, "blue");
					blueLion->print(time);
					blueAllLions.push_back( blueLion );
				}else if( availableBlue(dragonLifeVector[i]) ){
					blueDragon = new Dragon(dragonLifeVector[i], blueId, "blue");
					blueDragon->print(time);
					blueAllDragons.push_back(blueDragon);
				}else if(!blueFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " blue headquarter stops making warriors" << endl;
					blueFinished = true;
				}	
			}else if(time%5==3){
				if( availableRed( ninjaLifeVector[i] ) ){
					redNinja = new Ninja( ninjaLifeVector[i], redId, "red" );
					redNinja -> print(time);
					redAllNinjas.push_back(redNinja);
				}else if( availableRed(dragonLifeVector[i]) ){
					redDragon = new Dragon(dragonLifeVector[i], redId, "red");
					redDragon->print(time);
					redAllDragons.push_back(redDragon);
				}else if( availableRed(icemanLifeVector[i]) ){
					redIceman = new Iceman( icemanLifeVector[i], redId, "red" ); 
					redIceman -> print(time);
					redAllIcemans.push_back( redIceman );
				}else if( availableRed(lionLifeVector[i]) ){
					redLion = new Lion( lionLifeVector[i], redId, "red");
					redLion->print(time);
					redAllLions.push_back( redLion );
				}else if( availableRed(wolfLifeVector[i]) ){
					redWolf = new Wolf( wolfLifeVector[i], redId, "red");
					redWolf->print(time);
					redAllWolfs.push_back(redWolf);
				}else if(!redFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " red headquarter stops making warriors" << endl;
					redFinished = true;
				}
			
			
				if( availableBlue(icemanLifeVector[i]) ){
					blueIceman = new Iceman( icemanLifeVector[i], blueId, "blue" ); 
					blueIceman -> print(time);
					blueAllIcemans.push_back( blueIceman );
				}else if( availableBlue(wolfLifeVector[i]) ){
					blueWolf = new Wolf( wolfLifeVector[i], blueId, "blue");
					blueWolf->print(time);
					blueAllWolfs.push_back(blueWolf);
				}else if(availableBlue(lionLifeVector[i])){
					blueLion = new Lion( lionLifeVector[i], blueId, "blue");
					blueLion->print(time);
					blueAllLions.push_back( blueLion );
				}else if( availableBlue(dragonLifeVector[i]) ){
					blueDragon = new Dragon(dragonLifeVector[i], blueId, "blue");
					blueDragon->print(time);
					blueAllDragons.push_back(blueDragon);
				}else if( availableBlue(ninjaLifeVector[i]) ){
					blueNinja = new Ninja( ninjaLifeVector[i], blueId, "blue" );
					blueNinja -> print(time);
					blueAllNinjas.push_back(blueNinja);
				}else if(!blueFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " blue headquarter stops making warriors" << endl;
					blueFinished = true;
				}	
			}else if(time%5==4){
				if( availableRed(dragonLifeVector[i]) ){
					redDragon = new Dragon(dragonLifeVector[i], redId, "red");
					redDragon->print(time);
					redAllDragons.push_back(redDragon);
				}else if( availableRed(icemanLifeVector[i]) ){
					redIceman = new Iceman( icemanLifeVector[i], redId, "red" ); 
					redIceman -> print(time);
					redAllIcemans.push_back( redIceman );
				}else if( availableRed(lionLifeVector[i]) ){
					redLion = new Lion( lionLifeVector[i], redId, "red");
					redLion->print(time);
					redAllLions.push_back( redLion );
				}else if( availableRed(wolfLifeVector[i]) ){
					redWolf = new Wolf( wolfLifeVector[i], redId, "red");
					redWolf->print(time);
					redAllWolfs.push_back(redWolf);
				}else if( availableRed( ninjaLifeVector[i] ) ){
					redNinja = new Ninja( ninjaLifeVector[i], redId, "red" );
					redNinja -> print(time);
					redAllNinjas.push_back(redNinja);
				}else if(!redFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " red headquarter stops making warriors" << endl;
					redFinished = true;
				}
			
			
				if( availableBlue(wolfLifeVector[i]) ){
					blueWolf = new Wolf( wolfLifeVector[i], blueId, "blue");
					blueWolf->print(time);
					blueAllWolfs.push_back(blueWolf);
				}else if(availableBlue(lionLifeVector[i])){
					blueLion = new Lion( lionLifeVector[i], blueId, "blue");
					blueLion->print(time);
					blueAllLions.push_back( blueLion );
				}else if( availableBlue(dragonLifeVector[i]) ){
					blueDragon = new Dragon(dragonLifeVector[i], blueId, "blue");
					blueDragon->print(time);
					blueAllDragons.push_back(blueDragon);
				}else if( availableBlue(ninjaLifeVector[i]) ){
					blueNinja = new Ninja( ninjaLifeVector[i], blueId, "blue" );
					blueNinja -> print(time);
					blueAllNinjas.push_back(blueNinja);
				}else if( availableBlue(icemanLifeVector[i]) ){
					blueIceman = new Iceman( icemanLifeVector[i], blueId, "blue" ); 
					blueIceman -> print(time);
					blueAllIcemans.push_back( blueIceman );
				}else if(!blueFinished){
					cout << setfill('0') << setw(3);
					cout << time;
					cout << " blue headquarter stops making warriors" << endl;
					blueFinished = true;
				}	
			}
			
			
			if( redFinished && blueFinished) break;
			time++;
		}
		
		for(int i=0;i<redAllIcemans.size();i++){
			delete redAllIcemans[i];
		}
		
		for(int i=0;i<blueAllIcemans.size();i++){
			delete blueAllIcemans[i];
		}
		
		for(int i=0;i<redAllLions.size();i++){
			delete redAllLions[i];
		}
		
		for(int i=0;i<blueAllLions.size();i++){
			delete blueAllLions[i];
		}
		
		for(int i=0;i<redAllWolfs.size();i++){
			delete redAllWolfs[i];
		}
		
		for(int i=0;i<blueAllWolfs.size();i++){
			delete blueAllWolfs[i];
		}
		
		for(int i=0;i<redAllNinjas.size();i++){
			delete redAllNinjas[i];
		}
		
		for(int i=0;i<blueAllNinjas.size();i++){
			delete blueAllNinjas[i];
		}
		
		for(int i=0;i<redAllDragons.size();i++){
			delete redAllDragons[i];
		}
		
		for(int i=0;i<blueAllDragons.size();i++){
			delete blueAllDragons[i];
		}
	}
	
	return 0;
}
