#!/usr/bin/env python2.7
import SimpleHTTPServer
import SocketServer
import logging

PORT = 8000

class RequestHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
    def do_GET(self):
        logging.error(self.headers)
        SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self)

Handler = RequestHandler
httpd = SocketServer.TCPServer(("", PORT), Handler)

httpd.serve_forever()
