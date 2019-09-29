#include "crow.h"
#include <iostream>
#include <unistd.h>
#include <snap.h>


int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    .methods("POST"_method)
    ([](const crow::request& req) {
     	auto x = crow::json::load(req.body);
	if (!x)
	        return crow::response(400);
        char* file_path = x["path"].s().s_;
	char* out_pic = x["out"].s().s_;
	double shot_time =x["time"].d();
	//截图
     	SnapShot(file_path,out_pic,shot_time);
	
	crow::json::wvalue resp;
	resp["code"] = 0;
	resp["message"] = "ok";
	std::string s = crow::json::dump(resp);
	std::ostringstream os;
        os << s;
	return crow::response(os.str());
    });
    app.port(18081).multithreaded().run();
}
