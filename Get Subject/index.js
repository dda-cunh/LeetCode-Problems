const fs = require('fs');
const puppeteer = require('puppeteer');

const url = 'https://leetcode.com/problems/' + process.argv[3];
const elementClass = '_1l1MA';
const outputFilePath = '../' + process.argv[2] + '/'
						+ process.argv[3] + '/subject';

if (!url) {
  console.error('Usage: node index.js URL');
  process.exit(1);
}

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto(url);
  await page.waitForSelector(`div.${elementClass}`);
  const text = await page.$eval(`div.${elementClass}`, element => element.textContent.trim());
  fs.writeFileSync(outputFilePath, text);
  fs.appendFileSync(outputFilePath, '\n');
  await browser.close();
})();
