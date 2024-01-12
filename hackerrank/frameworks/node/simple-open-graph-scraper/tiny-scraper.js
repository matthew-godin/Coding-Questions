const { EventEmitter } = require("stream");

class TinyScraper extends EventEmitter {
    runScraper = (url) => {
        this.emit('scrapeStarted', url);
    };

    constructor(url, timeout = 2000) {
        super();
        this.url = url;
        this.timeout = timeout;
        new Promise((resolve) => {
            setTimeout(() => {
                this.emit('timeout');
            }, timeout);
            resolve();
        });
        new Promise((resolve) => {
            this.runScraper(url);
            resolve();
        });
    }
}

module.exports = TinyScraper;