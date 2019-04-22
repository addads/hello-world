// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/writer.h"
#include "rapidjson-master/include/rapidjson/stringbuffer.h"

using namespace rapidjson;
int main() {
   
   const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
   Document d;
   d.Parse(json);

   Document::AllocatorType& allocator = d.GetAllocator();

   Value& s = d["stars"];
   s.SetInt(s.GetInt() + 100);

   d.AddMember("portocale", "mere", allocator);
   d.AddMember("animal", "elefant", allocator);

   Value array(rapidjson::kArrayType);
   array.PushBack("temperatura", allocator).PushBack(15, allocator);
   d.AddMember("vreme", array, allocator);

   StringBuffer buffer;
   Writer<StringBuffer> writer(buffer);
   d.Accept(writer);
   
   std::cout << buffer.GetString() << std::endl;

   return 0;
}