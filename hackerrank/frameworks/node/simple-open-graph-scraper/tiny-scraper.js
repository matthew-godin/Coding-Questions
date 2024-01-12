const { EventEmitter } = require("stream");
var http = require('http');
var { parse } = require('node-html-parser');

class TinyScraper extends EventEmitter {
    runScraper = (url) => {
        http.get(url, res => {
            let data = [];
            if (res.statusCode !== 200) {
                this.emit('error', 'Status code: ' + res.statusCode.toString());
            }
            this.emit('scrapeStarted', url);
            res.on('data', chunk => {
                data.push(chunk);
            });
            res.on('end', () => {
                let scrape = {
                    title: '',
                    description: '',
                    image: '',
                };
                const root = parse(Buffer.concat(data).toString());
                const metaTags = root.getElementsByTagName('head')[0].getElementsByTagName('meta');
                for (let metaTag of metaTags) {
                    let property = metaTag.getAttribute('property');
                    if (property) {
                        let content = undefined;
                        switch (property.toString()) {
                            case 'og:title':
                                content = metaTag.getAttribute('content');
                                if (content) {
                                    scrape.title = content.toString();
                                }
                                break;
                            case 'og:description':
                                content = metaTag.getAttribute('content');
                                if (content) {
                                    scrape.description = content.toString();
                                }
                                break;
                            case 'og:image':
                                content = metaTag.getAttribute('content');
                                if (content) {
                                    scrape.image = content.toString();
                                }
                                break;
                        }
                    }
                }
                this.emit('scrapeSuccess', scrape);
            });
        }).on('error', err => { });
    };

    constructor(url, timeout = 2000) {
        super();
        new Promise((resolve) => {
            setTimeout(() => {
                this.emit('timeout');
            }, timeout);
            resolve();
        });
        new Promise((resolve) => {
            setTimeout(() => {
                this.runScraper(url);
            }, 50);
            resolve();
        });
    }
}

module.exports = TinyScraper;