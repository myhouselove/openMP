#include<iostream>
using namespace std;


enum Direction
{
 North,South,East,West
};
class MapSite{
    public:
    	MapSite()
		{
			cout<<endl;
		}
		bool flag;//0 is wall;1 is door in wall
    	virtual void Enter() = 0;

};


class Wall : public MapSite{
	public:
		Wall();
		virtual void Enter(){cout<<""<<endl;}
		Direction _side;
	private:
		bool _isBroken;
		
};
Wall::Wall()
{
	_isBroken = 0;
	this->flag = 0;
}
class Room : public MapSite{
	public:
		Room(int roomNum);
		MapSite* GetSide(Direction d1) const;
		void setSide(Direction,MapSite*);
		int getRoomNum(){return this->_roomNumber;}
		
		virtual void Enter(){
		cout<<"12312312"<<endl;
		}
	private:
		MapSite* _sides[4];
		int _roomNumber;
		bool _doorInWall;
};
Room::Room(int roomNum)
{
	this->_roomNumber = roomNum;
}
void Room::setSide(Direction d1,MapSite* w1)
{
	this->_sides[d1] = w1;
}

MapSite* Room::GetSide(Direction d1) const
{
	return this->_sides[d1];
}
class Door : public MapSite{
	public:
		Door(Room* = 0,Room* = 0){
		 this->flag = 1;
		 _isOpen = 0;
		}
			
		virtual void Enter(){
		cout<<endl;
		}
		Room* OtherSideFrom(Room*);
	private:
		Room* _room1;
		Room* _room2;
		bool _isOpen;
};
class Maze{
	public:
		 Maze(){
		 numberRo = 0;
		 int i = 100;
		 while(i--)
		 	this->rSet[i] = new Room(-1);
 		}
		 
		 void AddRoom(Room*);
		 Room* getRoomFromNum(int) const;
		 
 	private:
 		int numberRo;
 		Room *rSet[100];
 		
};
void Maze::AddRoom(Room* r1)
{
	if(this->rSet[r1->getRoomNum()]->getRoomNum() == -1) 
	{
		this->rSet[r1->getRoomNum()] = r1;
		this->numberRo++;
		cout<<"Add room success!"<<endl;
	}
	else
	{
		cout<<"your room number have existed!"<<this->rSet[r1->getRoomNum()]<<endl;
	}
}
Room* Maze::getRoomFromNum(int rn)  const
{
	if(this->rSet[rn] != NULL)
		return this->rSet[rn];
}
class MazeFactory{
	public:
		MazeFactory();
	virtual Maze* MakeMaze() const
	{return new Maze;}
	virtual Wall* MakeWall() const
	{return new Wall;}
	virtual Room* MakeRoom(int n) const
    {return new Room(n);}
    virtual Door* MakeDoor(Room* r1,Room* r2) const
	{return new Door(r1,r2);}
};

class MazeGame{
	public:
		MazeGame();
	
		Maze* CreateMaze(MazeFactory);
};


Maze* MazeGame::CreateMaze(MazeFactory factory)
{
	Maze* aMaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* aDoor = factory.MakeDoor(r1,r2);
	
	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);
	
	r1->setSide(North,factory.MakeWall());
	r1->setSide(East,aDoor);
	r1->setSide(South,factory.MakeWall());
	r1->setSide(West,factory.MakeWall());
	
	r2->setSide(North,factory.MakeWall());
	r2->setSide(East,factory.MakeWall());
	r2->setSide(South,factory.MakeWall());
	r2->setSide(West,aDoor);
	
	return aMaze;
}
int main()
{	
/*	Maze *maze = new Maze;
	Wall *w1 = new Wall;
	
	Room *r1 = new Room(12);
	Room *r2 = new Room(13);
	
	Door *do1 = new Door(r1,r2);
	r1->setSide(North,w1);
	r1->setSide(South,do1);
	
	
	maze->AddRoom(r1);
	maze->AddRoom(r2);
	
	if(r1->GetSide(North)->flag == 0)
		cout<<"it is the wall!"<<endl;
	if(r1->GetSide(South)->flag == 1)
		cout<<"it is the door!"<<endl;
	
	cout<<"the room1number is "<<r1->getRoomNum()<<endl;
	cout<<"the room2number is "<<r2->getRoomNum()<<endl;
*/

	
    cout<<"hello world!"<<endl;
    return 0;
}
