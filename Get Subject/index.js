const fs = require('fs');
const puppeteer = require('puppeteer');

const url = 'https://leetcode.com/problems/' + process.argv[3];
const elementClass = '_1l1MA';
const outputFilePath = '../' + process.argv[2] + '/'
            + process.argv[3] + '/subject.pdf';

if (!url) {
  console.error('Usage: node index.js URL');
  process.exit(1);
}

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto(url);
  await page.waitForSelector(`div.${elementClass}`);
  await page.evaluate(() => {
    const links = document.querySelectorAll('a');
    links.forEach(link => link.removeAttribute('href'));
  });
  await page.pdf({ path: outputFilePath, format: 'A3'});
  await browser.close();
})();
