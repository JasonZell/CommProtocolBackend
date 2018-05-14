'use strict';

const net = require('net');
const protobuf = require('protobufjs');

const HOST = '127.0.0.1';
const PORT = 7000;

const client = net.connect(PORT, HOST);

client.on('connect', () => {
  protobuf.load('./ProtoPacketsV2.proto')
    .then(root => {
      const Message = root.lookupType('ProtoPackets.Packet');
      const data = {
        VehicleInertialState: {
			vehicleid: 6,
			longitude: 34.05589,
			latitude : -117.819964,
			altitude : 44.33,
			roll : 55.44,
			pitch : 6.44,
			heading : 75.5,
			northspeed : 22.2,
			eastspeed : 9.2,
			verticalspeed : 11.2,
			rollrate : 11.3,
			pitchrate : 12.4,
			yawrate : 13.5,
			northaccel : 144.4,
			eastaccel : 155.4,
			verticalaccel : 16.5
        },
      };

      const e = Message.verify(data);
      if (e) throw Error(e);

      const message = Message.create(data);
      console.log(message);

      const buffer = Message.encodeDelimited(message).finish();
      client.write(buffer);
    }).catch(console.error);
});

// this will not happen since client isnt receiving anything
// client is only sending data
client.on('data', data => {
  console.log(`Received data: ${data}`);
});

client.on('close', () => {
  console.log('Client | Connection ended');
});

client.on('error', () => console.log('Client | Connection interrupted'));
