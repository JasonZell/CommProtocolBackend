'use strict';

const net = require('net');
const protobuf = require('protobufjs');

const HOST = '127.0.0.1';
const PORT = 6969;

const server = net.createServer();
server.listen(PORT, HOST, () => console.log(`Server | Listening on address ${HOST}:${PORT}`));

server.on('connection', client => {
  const { remotePort: port } = client;

  console.log(`Client:${port} | Connected`);

  client.on('data', data => {
    //console.log(data);

    protobuf.load('UGVMessage.proto')
      .then(root => {
        const ArmCommand = root.lookupType('UGV.ArmCommand');
        const message = ArmCommand.decodeDelimited(data);
        console.log(`Success: ${message.id}, ${message.position}`);
      }).catch(console.error);
  });

  client.on('end', () => console.log(`Client:${port} | Disconnected`));
});

server.on('error', console.log);
