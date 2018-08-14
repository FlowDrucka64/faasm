#pragma once

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>

#include <proto/faasm.pb.h>
#include <infra/infra.h>

#include <cpprest/http_listener.h>

using namespace Pistache;
using namespace web::http::experimental::listener;
using namespace web::http;

namespace edge {

    class RestServer {
    public:
        RestServer();

        void listen(const std::string &port);

        void handleGet(http_request request);
        void handlePost(http_request request);
        void handlePut(http_request request);

    private:
        http_listener *listener;
        std::shared_ptr<infra::RedisClient> redis;

        message::FunctionCall buildCallFromRequest(http_request *request);
    };


    class InvalidPathException : public std::exception {
    };

}