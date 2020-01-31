// Alayne Anderson
// hw4, activityType.cpp
// this file contains all the functions of the activity_type class

#include "Housing.h"
using namespace std;

// constructor
activity_type::activity_type() { data = NULL; }

// destructor
activity_type::~activity_type() {
  delete[] data->name;
  delete[] data->description;
  delete[] data->location;
  delete[] data->sqar_ft;
  delete[] data->num_rooms;
  data->name = NULL;
  data->description = NULL;
  data->location = NULL;
  data->sqar_ft= NULL;
  data->num_rooms = NULL;
  delete data;
  data = NULL;
}

// this function recieves a info struct as the argument
// and save thoes information into this class,
// return 1 finally
int activity_type::create(info &to_add) {
  data = new info;
  data->name = new char[strlen(to_add.name)];
  data->description = new char[strlen(to_add.description)];
  data->location = new char[strlen(to_add.location)];
  data->sqar_ft = new char[strlen(to_add.sqar_ft)];
  data->num_rooms = new char[strlen(to_add.num_rooms)];
  strcpy(data->name, to_add.name);
  strcpy(data->description, to_add.description);
  strcpy(data->location, to_add.location);
  strcpy(data->sqar_ft, to_add.sqar_ft);
  strcpy(data->num_rooms, to_add.num_rooms);
  data->distance_PSU = to_add.distance_PSU;
  return 1;
}

// this function pass back all the information in the class
// as a info struct, and retrun 1 finally
int activity_type::get_info(info &back) {
  back.name = new char[strlen(data->name)];
  back.description = new char[strlen(data->description)];
  back.location = new char[strlen(data->location)];
  back.sqar_ft= new char[strlen(data->sqar_ft)];
  back.num_rooms = new char[strlen(data->num_rooms)];
  strcpy(back.name, data->name);
  strcpy(back.description, data->description);
  strcpy(back.location, data->location);
  strcpy(back.sqar_ft, data->sqar_ft);
  strcpy(back.num_rooms, data->num_rooms);
  back.distance_PSU = data->distance_PSU;
  return 1;
}

// this function receives a particular location as the argument
// and compare it with the location in the class,
// pass the info struct back and return 1  if matched.
// otherwise, return 0
int activity_type::retrieve(char location[], info &back) {
  if (data) {
    if (strcmp(data->location, location) == 0) {
      back.name = new char[strlen(data->name)];
      back.description = new char[strlen(data->description)];
      back.location = new char[strlen(data->location)];
      back.sqar_ft = new char[strlen(data->sqar_ft)];
      back.num_rooms = new char[strlen(data->num_rooms)];
      strcpy(back.name, data->name);
      strcpy(back.description, data->description);
      strcpy(back.location, data->location);
      strcpy(back.sqar_ft, data->sqar_ft);
      strcpy(back.num_rooms, data->num_rooms);
      back.distance_PSU = data->distance_PSU;
      return 1;
    }
  }
  return 0;
}

// this function displays all the information
// in this class and return 1 if it exists,
// otherwise return 0
int activity_type::display() {
  if (data) {
    cout << "-----------" << endl;
    cout << "name: " << data->name << endl;
    cout << "description: " << data->description << endl;
    cout << "location: " << data->location << endl;
    cout << "distance from PSU: " << data->distance_PSU << endl;
    cout << "square ft: " << data->sqar_ft << endl;
    cout << "number of rooms: " << data->num_rooms << endl;
    cout << "-----------" << endl;
    return 1;
  }
  return 0;
}

// this function returns the location in ths class
// if it exists
char *activity_type::get_location() {
  if (data)
    return data->location;
}

