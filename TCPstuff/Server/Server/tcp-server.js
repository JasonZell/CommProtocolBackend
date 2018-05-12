'use strict';


// const { ipcMain } = require('electron');
// const fs = require('fs');
const net = require('net');
const protobuf = require('protobufjs');

const HOST = '127.0.0.1';
const PORT = 6969;

const Packet = protobuf.loadSync('./ProtoPacketsV2.proto').lookupType('ProtoPackets.Packet');

/* Create an array of proto roots */
/*
let packets;
protobuf.load('./Packets.proto', (err, root) => {
  if (err) throw err;
  packets = root;
});
*/

const server = net.createServer();
server.listen(PORT, HOST, console.log('Ready'));

server.on('connection', socket => {
  socket.on('data', data => {
    const packet = getData(data);
    console.log(packet);
  });
});

/**
 * Checks roots if there is a proto that can decode the incoming message
 * @param {Buffer} buffer buffer to decode
 * @returns {Message} either the Message that decodes the data, or null if none are found
 */
function getData(buffer) {
  const message = Packet.decodeDelimited(buffer);
  const data = Packet.toObject(message);
  for (const packetType in data) {
    return {
      type: packetType,
      data: data[packetType],
    };
  }
  return null;
}
