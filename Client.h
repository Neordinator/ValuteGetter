#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

const static std::string MAIN_API = "www.cbr.ru";
const static std::string API_ARGUMENTS = "/scripts/";

namespace http = boost::beast::http;
using namespace std;

class Client {
public:
	static string getResponse(string ip) {
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);

		boost::asio::connect(socket, resolver.resolve(MAIN_API, "80"));
		string argument = API_ARGUMENTS + ip;
		http::request<http::string_body> req(http::verb::get, argument, 11);
		req.set(http::field::host, MAIN_API);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(socket, req);
		string response; {
			boost::beast::flat_buffer buffer;
			http::response<http::dynamic_body> res;
			http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}
		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return response;
	}
};

#endif CLIENT_H