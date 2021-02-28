# Software Probleemstelling 

> communicatie consept

<img src="./picture/communicatie consept.png">
De hardware (ESPxx) zal een verbinding aangaan met de remote server om al zijn data te kunnen versturen zodat de gebruiker, realtime, zijn gegevens kan bekijken. We moeten dus een protocol gebruiken dat de datakosten zo laag mogelijk zal houden. Hiervoor is MQTT een goed protocol, aangezien het low power is en relatief laag aan dataverbruik heeft. Op deze manier kunnen we bv. via een mobiele hotspot (afkomstig van een smartphone) de data doorsturen naar de remote server. Deze server zal dan de data stockeren en weergeven aan de gebruiker.


<!-- <img src="./picture/Node_Communicatie.png">
<a target="_blank" href="https://randomnerdtutorials.com/esp8266-and-node-red-with-mqtt/">Source Picture</a> -->


### MQTT protocol
<img src="https://wiki.dragino.com/images/thumb/c/cb/YuanliMQTT.png/400px-YuanliMQTT.png">
<div style="font-size: 75%; line-height: 0; position: relative; vertical-align: baseline; top: -0.5em">
<p>bron: <a href="https://wiki.dragino.com/index.php?title=Through_MQTT_to_upload_data">dragino.com</a></p>
</div>

> <i>'MQTT (Message Queuing Telemetry Transport) is an open OASIS and ISO standard (ISO/IEC 20922) lightweight, publish-subscribe network protocol that transports messages between devices.'</i> <a target="_blank" href="https://en.wikipedia.org/wiki/MQTT">wikipedia</a>

Zoals het citaat van wikipedia zegt, het is een lichtgewicht publish-subscribe netwerk dat data transporteerd tussen toestellen en is ideaal om te gebruiken bij IoT projecten. De client('s) zijn namelijk niet afhankelijk van de server. Dit komt omdat er tussen de client('s) en server(s) een <i>middleman</i> staat, genaamd de Broker. Deze Broker handeld alle gegevens. Men kan een subscribe op een topic en men kan een topic publishen. 

<p>Wat wilt zeggen dat als we subscriben, we gegevens opvragen als ze aanwezig zijn. Als we publishen, sturen we gegevens door naar de broker onder een bepaald topic.</p> 

Een topic is een soort van url (bv. /woonkaper/lamp) die dan achterliggend gegevens bevat. Hierop kan men subscriben en publishen.

<p>Door deze werkwijzen van MQTT, is het voor ons heel gemakkelijk om alles onder te verdelen in topics en subtopics. Er is ook veel documentaie online van dit protocol wat zegt dat er al veel mee gewerkt is. Dit komt ons ten goeden.</p>

Er bestaan verschillende Brokers. 1 van de bekenste in IoT is <a target="_blank" href="https://mosquitto.org/">Mosquitto Broker</a>. Deze bestaat voor verschillende platformen. Wij gaan opteren voor een Debian platform (Ubuntu, Raspbian, ...).

### Node-RED
<div style="display: flex; align-items: center; justify-content: center">
<div style="flex-basis: 40%">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2b/Node-red-icon.png/200px-Node-red-icon.png">
</div>
<div style="padding-left: 20px"><p>Node-RED is een open soure programma dat zeer modulair is omdat het over meer dan 100 plugins bevadt. Hiermee kunnen we alle kanten opgaan. Van MQTT tot Alexa smart Home System. Vandaar dat we dit gaan nemen. Het is een drag-drop-configure-link codering.</p></div>
</div>
