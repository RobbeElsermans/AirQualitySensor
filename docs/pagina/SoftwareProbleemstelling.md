# Software Probleemstelling 

> communicatie consept

<img src="./picture/communicatie consept.png">
De hardware (ESPxx) zal een verbinding moeten kunnen aangaan met de remote server om al zijn data te kunnen versturen zodat de gebruiker, realtime, zijn gegevens kan bekijken. We moeten dus een protocol gebruiken dat de datakosten zo laag mogelijk zal houden. Hiervoor is MQTT een goed protocol dat low power is en relatief laag aan dataverbruik. Op deze manier kunnen we bv. via een mobiele hotspot (afkomstig van een smartphone) de data doorsturen naar de remote server. Deze server zal dan de data stockeren en weergeven aan de gebruiker.


<!-- <img src="./picture/Node_Communicatie.png">
<a target="_blank" href="https://randomnerdtutorials.com/esp8266-and-node-red-with-mqtt/">Source Picture</a> -->


### MQTT protocol
> <i>'MQTT (Message Queuing Telemetry Transport) is an open OASIS and ISO standard (ISO/IEC 20922) lightweight, publish-subscribe network protocol that transports messages between devices.'</i> <a target="_blank" href="https://en.wikipedia.org/wiki/MQTT">wikipedia</a>

zoals het citaat van wikipedia zegt, het is een lichtgewicht, publish-subscribe netwerk dat data transporteerd tussen toestellen. Het is ideaal om te gebruiken bij IoT projecten. De client('s) zijn namelijk niet afhankelijk van de server. Dit komt omdat tussen de client('s) en server(s) een <i>middleman</i> staat genaamd de Broker. Deze Broker handeld ale gegevens. Men kan subscribe op een topic en men kan een topic publishen. 

<p>Wat wilt zeggen dat als we subscriben, we gegevens opvragen als ze aanwezig zijn. Als we publishen, sturen we gegevens door naar de broker onder een bepaald topic.</p> 

Een topic is een soort van url (bv. /woonkaper/lamp) die dan achterliggend gegevens bevat. hierop kan men subscriben en publishen.

<p>Door deze werkwijzen van MQTT maakt het voor ons heel gemakkelijk om alles onder te verdelen in topics en subtopics. Er is ook veel documentaie online van dit protocol wat maakt dat er al veel mee gewerkt is. Dit komt ons ten goeden.</p>

Er bestaan verschillende Brokers. 1 van de bekenste in IoT is <a target="_blank" href="https://mosquitto.org/">Mosquitto Broker</a>. Deze bestaat voor verschillende platformen. Wij gaan opteren voor een Debian platform (Ubuntu, Raspbian, ...).

### Node-RED