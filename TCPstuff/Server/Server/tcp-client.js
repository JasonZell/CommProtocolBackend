'use strict';

/*
This client side should be run from C++.

Run the tcp-server.js and connect it with the C++ client
*/

const net = require('net');
const protobuf = require('protobufjs');

const HOST = '127.0.0.1';
const PORT = 6969;

const client = net.connect(PORT, HOST);

client.on('connect', () => {
  console.log(`Client | Connected to ${HOST}:${PORT}`);

  protobuf.load('./Packets.proto')
    .then(root => {
      const Message = root.lookupType('Packet');
      const data = { msg1: { a: 10 } };

      const e = Message.verify(data);
      if (e) throw Error(e);

      const message = Message.create(data);
      const buffer = Message.encodeDelimited(message).finish();
      client.write(buffer);

    }).catch(console.error);
});

client.on('data', data => {
  console.log(`Client | Received data: ${data}`);
});

client.on('close', () => {
  console.log('Client | Connection ended');
});

client.on('error', () => console.log('Client | Connection failed'));

module.exports = {
  sendMessage: function(message) {
    client.write(message);
  },
};
