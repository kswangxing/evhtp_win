// main.cpp: 主程序入口
//
#include <iostream>
#include "evhtp.h"
#include <WinSock2.h>

evhtp_t* g_htp;

#define REGISTER_HTP_CB(path, cb, arg) evhtp_set_cb(g_htp, path, cb, arg)

void HtpCallBack(evhtp_request_t* req, void* a)
{
	std::cout << "recv a command" << std::endl;
	evhtp_headers_add_header(req->headers_out, evhtp_header_new("Content-Type", "application/json", 0, 0));
	evbuffer_add(req->buffer_out, "hello, evhtp! success.", sizeof("hello, evhtp! success."));
	evhtp_send_reply(req, EVHTP_RES_OK);
}

int main(int argc, const char* argv[])
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);

	evbase_t* evbase = event_base_new();
	g_htp = evhtp_new(evbase, NULL);
	evhtp_use_threads_wexit(g_htp, NULL, NULL, 16, NULL);

	REGISTER_HTP_CB("/iojs/base/config", HtpCallBack, nullptr);					// 配置接口，接受来自IOCMS的配置信息	
				
	evhtp_bind_socket(g_htp, "0.0.0.0", 8080, 1024);

	event_base_loop(evbase, 0);

	WSACleanup();

	return 0;
}
