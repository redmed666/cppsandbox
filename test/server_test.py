#!/usr/bin/env python
from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler

PORT = 8000

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        print(self.path)
        print(self.headers)

def main():
    port = 8000
    print("Listening on localhost:%s" %(port))
    server = HTTPServer(('',port), RequestHandler)

    server.serve_forever()

if __name__ == "__main__":
    main()
