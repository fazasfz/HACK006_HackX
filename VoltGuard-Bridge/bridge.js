const { SerialPort } = require('serialport');
const WebSocket = require('ws');

const port = new SerialPort({
  path: 'COM3',        // ⚠️ change if needed
  baudRate: 115200
});

const wss = new WebSocket.Server({ port: 8080 });

port.on('data', data => {
  const msg = data.toString().trim();

  // Only forward JSON lines
  if (msg.startsWith('{') && msg.endsWith('}')) {
    wss.clients.forEach(client => {
      if (client.readyState === 1) {
        client.send(msg);
      }
    });
  }
});

console.log("✅ VoltGuard Serial → WebSocket bridge running on ws://localhost:8080");
