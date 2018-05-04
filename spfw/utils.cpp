#include <map>
#include <vector>
#include "utils.h"
#include "json/json.h"
#include "json/json-forwards.h"

using namespace std;
//map<string, string> gmap;
vector<string> actvec;
string key ;
bool printJSONTree( const Json::Value &root, unsigned short depth /* = 0 */, map<string, string> &m) 
{
	depth += 1;
	printf("****size=%d***\n",root.size());
	if( root.size() > 0 ) { 
		for( Json::Value::const_iterator itr = root.begin() ; itr != root.end() ; itr++ ) { 
			for( int tab = 0 ; tab < depth; tab++) {
				printf("-"); 
			}   
			if( itr.key().isString() ) {
					key = itr.key().asString().c_str();
					printf("*****key=%s*****\n",key.c_str());
			}
			if (printJSONTree( *itr, depth, m) == false)
				return false;
		}   
		return true;
	}
	else {
		if( root.isString() ) {
			string cmd = root.asString();
				m.insert(pair<string, string>(key,cmd));
			if (key == "action") {
				if (actvec.size() > 0) {
					for (auto val : actvec) {
						if (val !=  cmd) {
							actvec.push_back(cmd);
						}
					}
				} else {
					actvec.push_back(cmd);
				}
			}

		}
	}   
	return true;
}

bool parse_json(string text,map<string,string> &gmap)
{

	printf("json text is : %s\n", text.c_str());

	Json::CharReaderBuilder builder;
	Json::CharReader  *reader = builder.newCharReader();

	Json::Value root;

	builder["collectComments"] = false;

	std::string errs;

	bool ok = reader->parse(text.c_str(), text.c_str() + text.size() , &root, &errs);
	delete reader;

	if (!ok) {
		fprintf(stderr, "Failed parse json %s.\n", errs.c_str());
		return false;
	}


	gmap.clear();
	if (printJSONTree(root, 3, gmap) == false)
		return false;

	return true;
}


